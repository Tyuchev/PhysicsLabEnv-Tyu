#version 430
in float dist;
out vec4 diffuseColor;

void main()
{
	diffuseColor = vec4(1, 0.5f-(1-dist), 0.1-((dist/10.0f)), 1);
}
