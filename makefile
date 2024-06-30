
default:
	gcc -o fondue_convert \
		main.c \
		utils/*.c

run:
	./fondue_convert assets/font_5x7.png test
