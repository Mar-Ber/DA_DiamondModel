data {
    int N;
    real carat[N];
    real clarity[N];
}

generated quantities {
    real alpha = normal_rng(-1500, 100); 
    real beta_1 = normal_rng(7000, 1000);
    real beta_2 = normal_rng(-250, 10);
    real sigma = exponential_rng(5);
    real price [N];
    for (i in 1:N) {
        price[i] = normal_rng(alpha + beta_1 * carat[i] + beta_2 * clarity[i], sigma);
    }
}