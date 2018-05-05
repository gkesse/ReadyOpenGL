//===============================================
// Structure Camera
struct Camera
{
	vec3 position;
	vec3 orientation;
	float rapidite;
};
//===============================================
void main()
{
	// Déclaration d'une structure Camera
	Camera maCamera;
	// Utilisation
	maCamera.position = vec3(2.0, 5.0, 2.0);
	maCamera.rapidite = 0.5;
}
//===============================================
