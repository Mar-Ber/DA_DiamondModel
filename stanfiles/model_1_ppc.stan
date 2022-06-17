data {
    int N;
    vector[N] carat;
    array [N] int <lower=1, upper=8> clarity;
}

generated quantities {
    vector[8] alpha_clarity;
    vector[8] beta_clarity;
    for (i in 1:8){
        alpha_clarity[i] = normal_rng(-1000,10);
        beta_clarity[i] = normal_rng(10000,2000);
    }
    real sigma = exponential_rng(10);
    vector[N] price;
    for (i in 1:N){
        price[i] = normal_rng(alpha_clarity[clarity[i]]+ beta_clarity[clarity[i]] * carat[i], sigma);
    }
}