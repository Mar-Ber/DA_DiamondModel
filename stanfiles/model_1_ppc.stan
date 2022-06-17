data {
    int N;
    vector[N] carat;
    array [N] int <lower=1, upper=5> cut;
}

generated quantities {
    vector[5] alpha_cut;
    vector[5] beta_cut;
    for (i in 1:5){
        alpha_cut[i] = normal_rng(-1000,10);
        beta_cut[i] = normal_rng(8000,1800);
    }
    real sigma = exponential_rng(10);
    vector[N] price;
    for (i in 1:N){
        price[i] = normal_rng(alpha_cut[cut[i]]+ beta_cut[cut[i]] * carat[i], sigma);
    }
}