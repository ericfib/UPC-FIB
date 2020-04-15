#version 330 core

#define glF gl_FragCoord

in vec3 fcolor;
out vec4 FragColor;

void main() {
	if (fcolor == vec3(1,0,0)) {
		if (int(glF.x) % 10 < 4) discard;
	}
    FragColor = vec4(fcolor, 1.);
}
