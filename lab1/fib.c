#define N 28

int fib(int n) {
    if (n < 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {

    fib(N);

    return 0;
}
