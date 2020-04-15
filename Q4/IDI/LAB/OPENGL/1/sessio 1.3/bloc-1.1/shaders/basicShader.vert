#version 330 core

in vec3 vertex;
in vec3 color;
out vec3 fcolor;

uniform float escala;
uniform mat4 TG; 
void main()  {
    fcolor = color;
    gl_Position = TG * vec4 (vertex*escala, 1.0);
    
}
