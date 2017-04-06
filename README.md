# improved-potato
The goal is to plot RGB pixel values in a 3 dimensional volume matrix to help with interpreting heightmap values to achieve better resolution in terrain generation.

Currently I'm using colored heightmaps ![Screenshot](h_color.png) which I feed to my [GrayscaleConverter.cs](https://github.com/kenwi/scripts-misc/blob/master/GrayscaleConverter.cs), guided by the colormap ![Screenshot](colormap.png) to produce grayscale heightmaps ![Screenshot](c_grayscale.png) which I then use to produce  

![Screenshot](shadowmapped.png)
![Screenshot](textured.png)
![Screenshot](textured2.png)
