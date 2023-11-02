SRC =	philo.c  \
		actions.c \
		errors.c \
		initialisation.c \
		process.c \
		utils.c 

OBJS = ${SRC:.c=.o}

RM = rm -f
NAME = philo


GREEN = $(shell tput setaf 2)
BOLD = $(shell tput bold)
RESET = $(shell tput sgr0)

all :  ${NAME}

${LFT}:
				@make -s -C ./ft_printf/ all
				@make -s -C ./libft/ all

${NAME} :    ${OBJS} ${LFT} 
				@gcc -Wall -Werror -Wextra -g  -D_REENTRANT -no-pie ${OBJS}  -o ${NAME} -lpthread
				@echo "$(BOLD)$(GREEN)✅ Done !$(RESET)"


clean :
				@${RM} ${OBJS} 

fclean :    clean
						@${RM} ${NAME} a.out

re: fclean all

.PHONY: all clean fclean re 