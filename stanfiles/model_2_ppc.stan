data {
    int N;
    vector[N] carat;
    array [N] int <lower=1, upper=5> cut;
    array [N] int <lower=1, upper=8> clarity;
}

generated quantities {
    vector[5] alpha_cut;
    vector[5] beta_cut;
    for (i in 1:5){
        alpha_cut[i] = normal_rng(-1000,10);
        beta_cut[i] = normal_rng(500,100);
    }

    vector[8] alpha_clarity;
    vector[8] beta_clarity;
    for (i in 1:8){   
        alpha_clarity[i] = normal_rng(-1000,10);
        beta_clarity[i] = normal_rng(10000,2000);
    }

    real sigma = exponential_rng(10);

    vector[N] price;
    for (i in 1:N){
        price[i] = normal_rng(alpha_cut[cut[i]] + alpha_clarity[clarity[i]] + (beta_cut[cut[i]] + beta_clarity[clarity[i]]) * carat[i], sigma);
    }
}