# SPRITE
The sprite format is used to define 8 bit depth pixelated sprites. I understand this is overkill. But I can't use a format like PPM or BMP because of how inefficient they are and I can't understand compressed formats like PNG.

# FORMAT
The first 4 bytes of the file represesnt the side dimension of the sprite, the next side*side bytes each represent the respective monocolour pixels, each consisting of an 8 bit number. Note that zero represents a transparent pixel. It wont be rendered. The blackest color has a value of 1.
