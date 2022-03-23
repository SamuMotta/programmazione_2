#include <iostream>

using namespace std;

float* Interact (int interactions[], int n) {
    
    float* score = new float[n];

    for (int i = 0; i < n; i++) {

        if (i < 3) {
            score[i] = interactions[i];
        }
        else {
            score[i] = 0.25*interactions[i-3]+0.3*interactions[i-2]+0.5*interactions[i-1]+interactions[i];
        }
    }
    
    return score;
}

float* Frequency (int timestamps[], int n) {
    
    float* frequency = new float[n];

    frequency[0] = 0.0;

    float partialSum = 0.0;

    for (int i = 0; i < n; i++) {
        partialSum += timestamps[i] - timestamps[i-1];
        frequency[i] = partialSum / i;
    }

    return frequency;
}

float* Popularity (int interactions[], int timestamps[], int n) {

    float* interactions = Interact(interactions, n);
    float* frequency = Frequency(timestamps, n);

    float* popularity = new float[n];
    float alpha = 0.66;

    for (int i = 0; i < n; i++) {
        popularity[i] = alpha*interactions[i]+(1-alpha)*frequency[i];
    }

    return popularity;
}

float SommaMassima (float S[], int n) {

    float _max = 0.0;
	float somma= _max;
	for(int j = 0; j < n; j++) {

		if (somma > 0) {
			 somma = somma + S[j];
		} 
        else {
            //j è il punto di inizio del segmento di somma massima
			somma = S[j];
		}

		if (somma > _max) {
            //j è il punto di fine del segmento di somma massima
             _max = somma;
        }
	}
	return _max;

}


int main() {

}