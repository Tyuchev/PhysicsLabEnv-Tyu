#version 430
uniform mat4 ViewProjection;
uniform mat4 BillBoardViewProjection;

uniform int ParticleOffset;

out float dist;

layout(std430, binding = 0) readonly buffer Positions
{
    vec4 ReadPosAndScale[];
};

const vec3 TriangleBaseVertices[] = {
	vec3(0.5, 0.5, 0),
	vec3(-0.5, 0.5, 0),
	vec3(-0.5, -0.5, 0),
	vec3(0.5, 0.5, 0),
	vec3(-0.5, -0.5, 0),
	vec3(0.5, -0.5, 0)
};

void main()
{
	int localIndex = gl_VertexID % 6;
	int index1D = ParticleOffset + gl_VertexID / 6;
	vec4 translation = vec4(ReadPosAndScale[index1D].xyz, 1);
	float scale = ReadPosAndScale[index1D].w;
	vec4 projectedVertexPos = BillBoardViewProjection * vec4(TriangleBaseVertices[localIndex] * scale,1);
	gl_Position = ViewProjection * translation + projectedVertexPos;
	dist = length(translation) / 550.0f;
}
