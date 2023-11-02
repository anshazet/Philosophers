SRC =	philo_bonus.c  \
		actions_bonus.c \
		errors_bonus.c \
		initialisation.c \
		process_bonus.c \
		utils_bonus.c 

OBJS = ${SRC:.c=.o}

RM = rm -f
NAME = philo_bonus
CFLAGS = -Wall -Werror -Wextra -g -fPIE


GREEN = $(shell tput setaf 2)
BOLD = $(shell tput bold)
RESET = $(shell tput sgr0)

all :  ${NAME}

${LFT}:
				@make -s -C ./ft_printf/ all
				@make -s -C ./libft/ all

${NAME} :    ${OBJS} ${LFT} 
				@gcc -Wall -Werror -Wextra -g -pthread -no-pie ${OBJS}  -o ${NAME} -lpthread
				@echo "$(BOLD)$(GREEN)✅ Done !$(RESET)"


clean :
				@${RM} ${OBJS} 

fclean :    clean
						@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus checker