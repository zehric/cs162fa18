int numBatterInBowl = 0;
int numEggInBowl = 0;
bool readyToEat = false;
pthread_mutex_t lock;
pthread_cond_t needIngredients;
pthread_cond_t readyToBake;
pthread_cond_t startEating;
void* batterAdder(void* arg)
{
	pthread_mutex_lock(&lock);
	while (1) {
		while (numBatterInBowl || readyToEat) {
			pthread_cond_wait(&needIngredients, &lock);
		}
		addBatter(); // Sets numBatterInBowl += 1
		pthread_cond_signal(&readyToBake);
	}
}

void* eggBreaker(void* arg)
{
	pthread_mutex_lock(&lock);
	while (1) {
		while (numEggInBowl >= 2 || readyToEat) {
			pthread_cond_wait(&needIngredients, &lock);
		}
		addEgg(); // Sets numEggInBowl += 1
		pthread_cond_signal(&readyToBake);
	}
}
void* bowlHeater(void* arg)
{
	pthread_mutex_lock(&lock);
	while (1) {
		while (numEggInBowl < 2 || numBatterInBowl < 1) {
			pthread_cond_wait(&readyToBake, &lock);
		}
		heatBowl(); // Sets readyToEat = true, numBatterInBowl = 0, numEggInBowl = 0
		pthread_cond_signal(&startEating);
	}
}
void* cakeEater(void* arg)
{
	pthread_mutex_lock(&lock);
	while (1) {
		while (!readyToEat) {
			pthread_cond_wait(&startEating, &lock);
		}
		eatCake(); // Sets readyToEat = false and cleans the bowl for another cake
		pthread_cond_broadcast(&needIngredients);
	}
}
int main(int argc, char *argv[])
{
	// Initialize mutex and condition variables
	// Start threads: 1 batterAdder, 2 eggBreakers, 1 bowlHeater, and 1 cakeEater
	// main() sleeps forever
}
