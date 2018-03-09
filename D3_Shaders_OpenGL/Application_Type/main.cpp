//===============================================
// Application de texture avec GL_REPLACE
Couleur = texture2D(tex0, gl_TexCoord[0].xy) ;
//===============================================
// Application de texture avec GL_MODULATE
couleur *= texture2D(tex0, gl_TexCoord[0].xy) ;
//===============================================
// Application de texture avec GL_DECAL
Vec4 couleurText = texture2D(tex0, gl_TexCoord[0].xy) ;
vec3 coul = mix(color.rgb, couleurText.rgb, couleurText.a) ;
couleur = vec4(coul, color.a);
//===============================================
// Application de texture avec GL_BLEND
Vec4 couleurText = texture2D(tex0, gl_TexCoord[0].xy) ;
vec3 coul = mix(color.rgb, gl_TextureEnvColor[0].rgb, couleurText.rgb) ;
couleur = vec4(coul, color.a * couleurText.a);
//===============================================
// Application de texture avec GL_BLEND
Vec4 couleurText = texture2D(tex0, gl_TexCoord[0].xy) ;
vec3 coul = mix(color.rgb, gl_TextureEnvColor[0].rgb, couleurText.rgb) ;
couleur = vec4(coul, color.a * couleurText.a);
//===============================================
// Application de texture avec GL_ADD
Vec4 couleurText = texture2D(tex0, gl_TexCoord[0].xy) ;
color.rgb *= couleurText.rgb;
color.a *= couleurText.a ;
couleur = clamp(color,0.0, 1.0);
//===============================================
// Calcul de coordonnées de texture pour GL_SPHERE_MAP
vec2 sphereMap(in vec3 cameraPosition, in vec3 normal)
{
	float m ;
	vec3 r, u ;
	u = normalize(cameraPosition) ;
	r =reflect(u, normal) ;
	m = 2.0 * sqrt(r.x * r.x + r.y * r.y + (r.z + 1.0) * (r.z + 1.0)) ;
	return vec2(r.x / m + 0.5, r.y / m + 0.5);
}
//===============================================
// Calcul de coordonnées de texture pour GL_REFLECTION_MAP
vec3 reflectionMap(in vec3 cameraPosition, in vec3 normal)
{
	vec3 u = normalize(cameraPosition) ;
	return (reflect(u,normal));
}
//===============================================
// Génération coordonnées texture
vec2 sphereMapCoord ;
vec3 reflectionCoord;
If ( isTexSphere )
{
	sphereMapCoord = sphereMap(cameraPosition,normal);
}
if ( isTexReflection )
{
	reflectionCoord = reflectionMap(cameraPostion,normal);
}
// Pour toutes les textures activées
for ( int i = 0 ; i < nombreTexture ; i++ )
{
	if ( isTexObject )
	{
		gl_TexCoord[i].s = dot(gl_Vertex, gl_ObjectPlaneS[i]) ;
		gl_TexCoord[i].t = dot(gl_Vertex, gl_ObjectPlaneT[i]) ;
		gl_TexCoord[i].p = dot(gl_Vertex, gl_ObjectPlaneR[i]) ;
		gl_TexCoord[i].q = dot(gl_Vertex, gl_ObjectPlaneQ[i]);
	}
	if ( isTexEye )
	{
		gl_TexCoord[i].s = dot(gl_Vertex, gl_EyePlaneS[i]) ;
		gl_TexCoord[i].t = dot(gl_Vertex, gl_EyePlaneT[i]) ;
		gl_TexCoord[i].p = dot(gl_Vertex, gl_EyePlaneR[i]) ;
		gl_TexCoord[i].q = dot(gl_Vertex, gl_EyePlaneQ[i]);
	}
	if ( isTexSphere )
	{
		gl_TexCoord[i] = vec4(sphereMapCoord, 0.0, 1.0);
	}
	if ( isTexReflection )
	{
		gl_TexCoord[i] = vec4(reflectionCoord, 1.0);
	}
	if ( isTexNormal )
	{
		gl_TexCoord[i] = vec4(normal, 1.0);
	}
}
//===============================================
// 
//===============================================
// 
//===============================================
// 
//===============================================
