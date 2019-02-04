#pragma once

const char* WORLD_SHADER_VERTEX = "#version 330 core \n"
""
"layout (location = 0) in vec3 in_pos;"
"layout (location = 1) in vec3 in_normal;"
"layout (location = 2) in vec2 in_uv;"
"layout (location = 3) in vec3 in_tangent;"
""
"uniform mat4 proj, view, model;"
""
"out vec3 fragmentPos;"
"out mat3 TBN;"
"out vec2 fragmentUV;"
""
"void main() {"
"	vec4 posInWorld = model * vec4(in_pos, 1.0);"
"	gl_Position = proj * view * posInWorld;"
""
"	mat3 normalMat = mat3(transpose(inverse(model)));"
""
"	vec3 normal = normalize(normalMat * in_normal);"
"	vec3 tangent = normalize(normalMat * in_tangent);"
"	vec3 bitangent = normalize(cross(normal, tangent));"
""
"	tangent = tangent * -1;"
""
"	fragmentPos = vec3(posInWorld);"
"	TBN = mat3(tangent, bitangent, normal);"
"	fragmentUV = in_uv;"
"}"
"";

const char * WORLD_SHADER_FRAGMENT = "#version 330 core \n"
""
"in vec3 fragmentPos;"
"in mat3 TBN;"
"in vec2 fragmentUV;"
""
"struct Material {"
"	vec3 diffuse;"
"	vec3 specular;"
"	vec3 emission;"
"	float shininess;"
"	float emissionAlpha;"
"};"
"uniform Material material;"
""
"struct DirectionalLight {"
"	vec3 direction;"
"	vec3 color;"
"	float intensity;"
"};"
"uniform DirectionalLight directionalLight;"
""
"uniform vec3 cameraPos;"
""
"uniform sampler2D diffuseTex;"
"uniform sampler2D normalTex;"
"uniform sampler2D specTex;"
"uniform int useTexture;"
"uniform int useNormalMap;"
"uniform int useSpecMap;"
""
"uniform vec2 diffuseScale;"
"uniform vec2 normalScale;"
"uniform vec2 specScale;"
""
"out vec4 fragColor;"
""
"vec3 calcDirectionalLight(DirectionalLight light, vec3 normal, vec3 cameraDir, vec3 specMapFactor);"
""
"void main() {"
"	vec3 normal;"
"	if (useNormalMap > 0)"
"		normal = normalize(TBN * (vec3(texture(normalTex, fragmentUV * normalScale)) * 2.0 - 1.0));"
"	else"
"		normal = TBN[2];"
""
"	vec3 cameraDir = normalize(cameraPos - fragmentPos);"
""
"	vec4 textureColor = vec4(1.0);"
"	if (useTexture > 0)"
"		textureColor = texture(diffuseTex, fragmentUV * diffuseScale);"
""
"	vec4 specMapFactor = vec4(1, 1, 1, 1);"
"	if(useSpecMap > 0)"
"		specMapFactor = normalize(texture(specTex, fragmentUV * specScale));"
""
"	vec3 totalLight = calcDirectionalLight(directionalLight, normal, cameraDir, vec3(specMapFactor));"
""
"	fragColor = vec4(totalLight, 1.0) * textureColor;"
""
"	fragColor = (1.0 - material.emissionAlpha) * fragColor + material.emissionAlpha * vec4(material.emission, 1.0);"
""
"	fragColor.rgb = pow(fragColor.rgb, vec3(1.0/2.2));"
"}"
""
"vec3 calcDirectionalLight(DirectionalLight light, vec3 normal, vec3 cameraDir, vec3 specMapFactor) {"
"	vec3 ambient = light.color * (material.diffuse * 0.1);"
""
"	float diffuseIntensity = max(dot(-light.direction, normal), 0);"
"	vec3 diffuse = (light.color * diffuseIntensity * light.intensity) * material.diffuse;"
""
"	vec3 halfwayDir = normalize(cameraDir - light.direction);"
"	float specularIntensity = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);"
"	vec3 specular = ((light.color * specularIntensity) * material.specular) * (specMapFactor);"
""
"	return ambient + diffuse + specular;"
"}";


const char * WORLD_SKYBOX_SHADER_VERTEX = "#version 330 core \n"
""
"layout (location = 0) in vec3 in_pos;"
"layout (location = 1) in vec3 in_normal;"
"layout (location = 2) in vec2 in_uv;"
"layout (location = 3) in vec3 in_tangent;"
""
"out vec3 fragmentUV;"
""
"uniform mat4 proj;"
"uniform mat4 view;"
""
"void main() {"
"	fragmentUV = normalize(in_pos);"
"	gl_Position = proj * view * vec4(in_pos, 1.0);"
"}";


const char * WORLD_SKYBOX_SHADER_FRAGMENT = "#version 330 core \n"
""
"in vec3 fragmentUV;"
""
"out vec4 fragColor;"
""
"uniform samplerCube skybox;"
""
"void main() {"
"	fragColor = texture(skybox, fragmentUV);"
"}";