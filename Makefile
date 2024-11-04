#==============================================================================#
#                                   LIBFT PROJECT                               #
#==============================================================================#

# Main target names
NAME = libft.a
EXEC = libft_tester.out

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                                #
#------------------------------------------------------------------------------#

# ANSI color codes for prettier output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Text style codes
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m

# Emojis for visual feedback
CHECK = ✓
CLEAN = 🧹
BUILD = 🔨
ROCKET = 🚀
BOOK = 📚
SPARKLES = ✨

#------------------------------------------------------------------------------#
#                            	  NAMES AND PATHS                                #
#------------------------------------------------------------------------------#

# Directory structure
BUILD_PATH = .build
SRC_PATH = srcs
BONUS_PATH = srcs_bonus
INC_PATH = incs
HEADERS = ${INC_PATH}/libft.h

# Source files for main library
SRCS = ${addprefix ${SRC_PATH}/,}

# Source files for bonus part
SRCS_BONUS = ${addprefix ${BONUS_PATH}/,}

# Object files derived from source files
OBJS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS:.c=.o}}}
OBJS_BONUS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS_BONUS:.c=.o}}}

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                              #
#------------------------------------------------------------------------------#

CC = cc                           # Compiler to use
CCFLAGS = -Wall -Wextra -Werror   # Compiler flags for warnings and errors
AR = ar rcs                       # Archive command to create static libraries
RM = rm -fr                       # Command to remove files/directories forcefully
MKDIR_P = mkdir -p                # Command to create directories (with parent)

INC = -I ${INC_PATH}              # Include path for header files

TMUX = tmux                       # Tmux command for terminal multiplexing

#------------------------------------------------------------------------------#
#                                    RULES                                      #
#------------------------------------------------------------------------------#

##  Compilation Rules for Libft  ##

all: ${NAME}                     # Default target: build the library

${BUILD_PATH}:                   # Create build directory if it doesn't exist
	@printf "\n${BLUE}${BOLD}Creating build directory...${RESET}\n"
	@${MKDIR_P} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} Build directory created successfully!${RESET}\n"

${NAME}: ${BUILD_PATH} ${OBJS}    # Build the static library from object files
	@printf "\n${YELLOW}${BOLD}${BUILD} Assembling ${WHITE}${NAME}${YELLOW}...${RESET}\n"
	@${AR} ${NAME} ${OBJS}
	@printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${NAME}${GREEN} created successfully!${RESET}\n"

${BUILD_PATH}/%.o: ${SRC_PATH}/%.c ${HEADERS}  # Compile source files into object files (main)
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

${BUILD_PATH}/%.o: ${BONUS_PATH}/%.c ${HEADERS}  # Compile bonus source files into object files (bonus)
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

bonus: ${BUILD_PATH} ${OBJS} ${OBJS_BONUS}   # Assemble bonus functions into the library
	@printf "\n${PURPLE}${BOLD}${SPARKLES} Assembling bonus functions...${RESET}\n"
	@${AR} ${NAME} ${OBJS} ${OBJS_BONUS}
	@printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${NAME}${GREEN} created successfully with BONUS!${RESET}\n"

##  Norms Rules  ##

norm_mandatory:                # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette ${SRC_PATH}/*.c ${INC_PATH}/*.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

norm_bonus:                    # Check norms for bonus sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette ${BONUS_PATH}/*.c ${INC_PATH}/*.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

norm_all:                     # Check norms for all sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette ${SRC_PATH}/*.c ${BONUS_PATH}/*.c ${INC_PATH}/*.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

##   Check for external functions  ##
check_external_functions: all               # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking External Functions...${RESET}\n"
	nm ./${NAME} | grep "U" | grep -v "__"
	@printf "${GREEN}${BOLD}${CHECK} External functions check completed!${RESET}\n"
	
##  Cleaning Rules  ##

clean:                       # Clean up object files and temporary build files 
	@printf "\n${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@${RM} ${OBJS} ${OBJS_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Object files cleaned!${RESET}\n"
	@${MAKE_CLEAN} ${TESTS_PATH}

fclean: clean               # Fully clean up by removing executables and build directories 
	@printf "${YELLOW}${BOLD}${CLEAN} Removing executable and build files...${RESET}\n"
	@${RM} ${NAME}
	@${RM} ${BUILD_PATH}
	@${RM} ${EXEC}
	@printf "${GREEN}${BOLD}${CHECK} All files cleaned!${RESET}\n"
	@${MAKE_FCLEAN} ${TESTS_PATH}

re: fclean ${NAME}          # Rebuild everything from scratch 

.PHONY: all test clean fclean re test norm start_tmux start_tmux_bonus   # Declare phony targets 
