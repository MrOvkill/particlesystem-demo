#version 330 core
out vec3 color;
in vec3 current;

void main() {
    vec3 now = current;
    now.r += 0.1;
    now.g += 0.1;
    now.b += 0.1;
    color = now;
}
