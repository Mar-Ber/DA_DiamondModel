data {
    int N;
    vector[N] znorm_carat;
    array [N] int <lower=1, upper =5> cut;
    array [N] int <lower=1, upper =8> clr;
    vector[N] y;
}

parameters {
    vector[8] cut_alpha;
    vector[5] clr_alpha;
    vector[8] cut_beta;
    vector[5] clr_beta;
    real <lower=0> sigma;
}
transformed parameters {
   array [N] real mu;
   for (i = 1:N){
    mu[i] = cut_alpha[cut[i]] +clr_alpha[clr[i]]+(cut_beta[cut[i]]+clr_beta[clr[i]])*znorm_carat[i];
   } 
}
model {
    clr_beta ~ normal(0,10);
    cut_beta ~ normal(0,10);
    ...
    for (i=1:N){
        y[i] ~ normal(mu[i], sigma);
    }
}
generated quantities {
   real price [N];
   for (i in 1:N){
    price[i] = normal_rng(mu[i], sigma);
   }
}