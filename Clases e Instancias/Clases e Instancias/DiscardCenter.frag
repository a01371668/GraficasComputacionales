#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

uniform vec2 Resolution; //Resolución de la ventana en pixeles.

void main(){

	vec2 p = gl_FragCoord.xy/Resolution; // Es la posición de pixel en la ventana en un rango de [(0,0),(1,1)]
	vec2 q = p - vec2(0.5f,0.5f); //Calculando un vector que va del pixel al centro de la ventana

	if(length(q) < 0.25f){ //Si el vector que tiene una medida menor a 0.25, descartamos el pixel
		discard;
	}

	FragColor = vec4(InterpolatedColor, 1.0f);
}