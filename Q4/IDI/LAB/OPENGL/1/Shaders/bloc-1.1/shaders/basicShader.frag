#version 330 core
#define glF gl_FragCoord

in vec3 fcolor;
out vec4 FragColor;

void main() {

        FragColor = vec4(fcolor, 1.);
//     if (glF.x > 354. && glF.y > 354.) {
//         FragColor = vec4(1, 0, 0, 1);
//     }
//     else if (glF.x > 354. && glF.y < 354.) {
//         FragColor = vec4(0, 0, 1, 1);
//     }
//     else if (glF.x < 354. && glF.y < 354.) {
//         FragColor = vec4(1, 1, 0, 1);
//     }
//     else if (glF.x < 354. && glF.y > 354.) {
//         FragColor = vec4(0, 1, 0, 1);
//     }
   
}

