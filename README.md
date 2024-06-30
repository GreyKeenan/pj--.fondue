
Fondue:

A personal project to implement basic, fixed-pixel-size, ascii fonts.

Why?
	1. I didnt want to use SDL_TTF
	2. its a fun exercise
	bonus: Im learning about PNG files & compression in general now

Features/plan:
	
	CLI tool to create some sort of simple custom font file format that is rly lightweight cuz few features
		Beginning by converting from a PNG
	decoding the custom font file format
	displaying the font
		Starting with SDL.
		to use in pj.sublime.c, which was the original purpose

This wont really be something anyone needs, since other libraries will do this with even more features. Its just a fun thing I think. Plus I like the idea of not using a bunch of other libraries if I can help it.
