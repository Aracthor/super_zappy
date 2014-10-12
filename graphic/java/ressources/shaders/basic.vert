/*
** basic.vert for libgl in /home/bonnet_v/programs/fun/libgl
** 
** Made by Bonnet Vivien
** Login   <bonnet_v@epitech.net>
** 
** Started on  Wed May 21 12:28:26 2014 Bonnet Vivien
** Last Update Sun Oct 12 04:17:19 2014 
*/

#version 330 core

layout (location = 0) in vec3	inPosition;
layout (location = 1) in vec3	inColor;
layout (location = 2) in vec2	inTexCoord0;
layout (location = 3) in vec3	inNormal;


uniform mat4	modelMatrix;
uniform mat4	projectionMatrix;
uniform mat4	viewMatrix;


out vec3        position;
out vec3	in_color;
out vec2	tex_coord;
smooth out vec3	normal;

void		main()
{
  // Transfer to fragment shader
  in_color = inColor;
  tex_coord = inTexCoord0;
  normal = vec4(inNormal, 0.0f).xyz;

  // Position calcul
  position = vec3(vec4(inPosition, 1.0f));
  /* gl_Position = vec4(position, 1.0f) * modelMatrix; */
  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(inPosition, 1.0f);
}
