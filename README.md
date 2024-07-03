
ARCHIVING: (not true github archive, just personal archive method)

	(reasoning taken from dev_pngs final commit)
	
		* I read up on zlib, DEFLATE, huffman coding, and lz77. See GreyKeenan/le.DEFLATE

		after doing so, I dont think that this fondue sub-project is really necessary at all. a custom font-file would just be less effective than using a PNG, plus the font should be packed together in a sprite sheet with other images.
			I dont really need a separate tool to encode them somehow, because now that I know how PNG encoding works, I can achieve what I would have wanted, if not more, just through an image editor & image-magick
		the decoding-for-the-sake-of-rendering-with-SDL part is still needed, but that doesn't need to be in its own repo.
		it will be modular, but if other independent utilities and stuff are just included within pj.sublime.c anyways, this one should be too
		
		plan to update master w/ this info (not that it really matters) and move to ar.fondue

		

		I will still be reusing/reworking some of the PNG-decoding code from this repo in pj.sublime.c


PRIOR README:

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
