#include <iostream>

int main(){

size_t K = 0;
size_t N = 0;
std::cin >> N >> K;
int difference = 0;
int prices[N];
for(int i = 0; i < N; i++) {
    std::cin >> prices[i];
}
for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N && j <= i + K; ++j){
        if (prices[j] - prices[i] > difference)
        difference = prices[j] - prices[i];
    }
}
std::cout << difference << std::endl;
return 0;
}