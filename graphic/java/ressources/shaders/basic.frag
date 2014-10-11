/*
** basic.frag for libgl in /home/bonnet_v/programs/fun/libgl
** 
** Made by Bonnet Vivien
** Login   <bonnet_v@epitech.net>
** 
** Started on  Wed May 21 11:24:03 2014 Bonnet Vivien
** Last Update Fri Oct 10 22:30:54 2014 
*/

#version 330 core

in vec4		in_color;
in vec2		tex_coord;


uniform bool		use_color;
uniform bool		use_texture;
uniform sampler2D	texture;


out vec4	fragColor;


void		main()
{
  float		coef;

  fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
  if (use_color)
    fragColor *= in_color;
  if (use_texture)
    fragColor *= texture2D(texture, tex_coord);

  fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f); // DEBUG
}
