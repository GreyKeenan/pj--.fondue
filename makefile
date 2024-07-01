
default:
	gcc -o fondue_convert \
		-iquote . \
		main.c \
		utils/*.c

run:
	./fondue_convert assets/font_5x7.png test
