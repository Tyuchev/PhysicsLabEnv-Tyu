#version 430

layout(std430, binding = 0) readonly buffer ReadBlockPositions
{
    vec4 ReadPosAndScale[];
};
layout(std430, binding = 1) readonly buffer ReadBlockColors
{
    vec4 ReadColors[];
};
layout(std430, binding = 2) readonly buffer ReadBlockVelocities
{
    vec4 ReadVelAndLifetime[];
};

layout(std430, binding = 3) writeonly buffer WriteBlockPositions
{
    vec4 WritePosAndScale[];
};
layout(std430, binding = 4) writeonly buffer WriteBlockColors
{
    vec4 WriteColors[];
};
layout(std430, binding = 5) writeonly buffer WriteBlockVelocities
{
    vec4 WriteVelAndLifetimes[];
};

layout(binding = 10) uniform EmitterBlock
{
	vec4 origin;
	vec4 dir;
	vec4 startColor;
	vec4 endColor;
	uint numParticles;
	float theta;
	float startSpeed;
	float endSpeed;
	float startScale;
	float endScale;
	float decayTime;
	float randomTimeOffsetDist;
	uint looping;
	uint fireOnce;
	uint _padding0;
	uint _padding1;
};

uniform float TimeStep;
uniform uvec3 Random;

//vec3 GetRandomConeDir(vec3 dir, float theta)
//{
//	//SphericalFibonacci()
//}

#define THREADS_X 1024
#define THREADS_Y 1
#define THREADS_Z 1
layout(local_size_x = THREADS_X, local_size_y = THREADS_Y, local_size_z = THREADS_Z) in;
void main()
{
	uint pid = gl_GlobalInvocationID.x;
	if (pid >= numParticles)
		return;
	
	vec3 pos = ReadPosAndScale[pid].xyz;
	float scale = ReadPosAndScale[pid].w;
	vec3 vel = ReadVelAndLifetime[pid].xyz;
	float lifetime = ReadVelAndLifetime[pid].w;

	lifetime -= TimeStep;
	if ((lifetime <= 0 && looping > 0) || fireOnce > 0)
	{
		// reset particle
		lifetime = decayTime;
		pos = origin.xyz;
	}

	vec3 acc = normalize(- pos) * 9.82f;
	vel += acc * TimeStep;
	pos += vel * TimeStep;

	WritePosAndScale[pid] = vec4(pos, scale);
	WriteVelAndLifetimes[pid]= vec4(vel,lifetime);
}