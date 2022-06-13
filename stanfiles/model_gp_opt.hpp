
// Code generated by stanc v2.29.1
#include <stan/model/model_header.hpp>
namespace model_gp_opt_model_namespace {

using stan::model::model_base_crtp;
using namespace stan::math;


stan::math::profile_map profiles__;
static constexpr std::array<const char*, 16> locations_array__ = 
{" (found before start of program)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 8, column 4 to column 35)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 9, column 4 to column 31)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 10, column 4 to column 35)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 14, column 11 to column 12)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 14, column 14 to column 15)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 14, column 4 to column 99)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 15, column 11 to column 12)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 15, column 14 to column 15)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 15, column 4 to column 49)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 17, column 4 to column 59)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 2, column 4 to column 21)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 3, column 15 to column 16)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 3, column 4 to column 18)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 4, column 11 to column 12)",
 " (in 'C:/Users/JAKUBB~1/DOCUME~1/PYCHAR~1/DA_DIA~1/STANFI~1/model_gp_opt.stan', line 4, column 4 to column 20)"};




class model_gp_opt_model final : public model_base_crtp<model_gp_opt_model> {

 private:
  int N;
  std::vector<double> carat;
  Eigen::Matrix<double, -1, 1> price__; 
  Eigen::Map<Eigen::Matrix<double, -1, 1>> price{nullptr, 0};
 
 public:
  ~model_gp_opt_model() { }
  
  inline std::string model_name() const final { return "model_gp_opt_model"; }

  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.29.1", "stancflags = "};
  }
  
  
  model_gp_opt_model(stan::io::var_context& context__,
                     unsigned int random_seed__ = 0,
                     std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    int current_statement__ = 0;
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static constexpr const char* function__ = "model_gp_opt_model_namespace::model_gp_opt_model";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      current_statement__ = 11;
      context__.validate_dims("data initialization","N","int",
           std::vector<size_t>{});
      N = std::numeric_limits<int>::min();
      
      
      current_statement__ = 11;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 11;
      stan::math::check_greater_or_equal(function__, "N", N, 1);
      current_statement__ = 12;
      stan::math::validate_non_negative_index("carat", "N", N);
      current_statement__ = 13;
      context__.validate_dims("data initialization","carat","double",
           std::vector<size_t>{static_cast<size_t>(N)});
      carat = 
        std::vector<double>(N, std::numeric_limits<double>::quiet_NaN());
      
      
      current_statement__ = 13;
      carat = context__.vals_r("carat");
      current_statement__ = 14;
      stan::math::validate_non_negative_index("price", "N", N);
      current_statement__ = 15;
      context__.validate_dims("data initialization","price","double",
           std::vector<size_t>{static_cast<size_t>(N)});
      price__ = 
        Eigen::Matrix<double, -1, 1>::Constant(N,
          std::numeric_limits<double>::quiet_NaN());
      new (&price) Eigen::Map<Eigen::Matrix<double, -1, 1>>(price__.data(), N);
        
      
      {
        std::vector<local_scalar_t__> price_flat__;
        current_statement__ = 15;
        price_flat__ = context__.vals_r("price");
        current_statement__ = 15;
        pos__ = 1;
        current_statement__ = 15;
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          current_statement__ = 15;
          stan::model::assign(price, price_flat__[(pos__ - 1)],
            "assigning variable price", stan::model::index_uni(sym1__));
          current_statement__ = 15;
          pos__ = (pos__ + 1);
        }
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    num_params_r__ = 1 + 1 + 1;
    
  }
  
  template <bool propto__, bool jacobian__ , typename VecR, typename VecI, 
  stan::require_vector_like_t<VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "model_gp_opt_model_namespace::log_prob";
    (void) function__;  // suppress unused var warning
    
    try {
      local_scalar_t__ alpha = DUMMY_VAR__;
      current_statement__ = 1;
      alpha = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(
                0, 130, lp__);
      local_scalar_t__ rho = DUMMY_VAR__;
      current_statement__ = 2;
      rho = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(0,
              1, lp__);
      local_scalar_t__ sigma = DUMMY_VAR__;
      current_statement__ = 3;
      sigma = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(
                0, 100, lp__);
      {
        current_statement__ = 4;
        stan::math::validate_non_negative_index("cov", "N", N);
        current_statement__ = 5;
        stan::math::validate_non_negative_index("cov", "N", N);
        Eigen::Matrix<local_scalar_t__, -1, -1> cov =
           Eigen::Matrix<local_scalar_t__, -1, -1>::Constant(N, N,
             DUMMY_VAR__);
        current_statement__ = 6;
        stan::model::assign(cov,
          stan::math::add(stan::math::cov_exp_quad(carat, alpha, rho),
            stan::math::diag_matrix(
              stan::math::rep_vector(stan::math::square(sigma), N))),
          "assigning variable cov");
        current_statement__ = 7;
        stan::math::validate_non_negative_index("L_cov", "N", N);
        current_statement__ = 8;
        stan::math::validate_non_negative_index("L_cov", "N", N);
        Eigen::Matrix<local_scalar_t__, -1, -1> L_cov =
           Eigen::Matrix<local_scalar_t__, -1, -1>::Constant(N, N,
             DUMMY_VAR__);
        current_statement__ = 9;
        stan::model::assign(L_cov, stan::math::cholesky_decompose(cov),
          "assigning variable L_cov");
        current_statement__ = 10;
        lp_accum__.add(
          stan::math::multi_normal_cholesky_lpdf<propto__>(price,
            stan::math::rep_vector(0, N), L_cov));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, 
  stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, 
  stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr> 
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    static constexpr bool propto__ = true;
    (void) propto__;
    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    int current_statement__ = 0; 
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    constexpr bool jacobian__ = false;
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "model_gp_opt_model_namespace::write_array";
    (void) function__;  // suppress unused var warning
    
    try {
      double alpha = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 1;
      alpha = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(
                0, 130, lp__);
      double rho = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 2;
      rho = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(0,
              1, lp__);
      double sigma = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 3;
      sigma = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(
                0, 100, lp__);
      out__.write(alpha);
      out__.write(rho);
      out__.write(sigma);
      if (stan::math::logical_negation((stan::math::primitive_value(
            emit_transformed_parameters__) || stan::math::primitive_value(
            emit_generated_quantities__)))) {
        return ;
      } 
      if (stan::math::logical_negation(emit_generated_quantities__)) {
        return ;
      } 
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, 
  stan::require_std_vector_t<VecVar>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline void transform_inits_impl(VecVar& params_r__, VecI& params_i__,
                                   VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      local_scalar_t__ alpha = DUMMY_VAR__;
      alpha = in__.read<local_scalar_t__>();
      out__.write_free_lub(0, 130, alpha);
      local_scalar_t__ rho = DUMMY_VAR__;
      rho = in__.read<local_scalar_t__>();
      out__.write_free_lub(0, 1, rho);
      local_scalar_t__ sigma = DUMMY_VAR__;
      sigma = in__.read<local_scalar_t__>();
      out__.write_free_lub(0, 100, sigma);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__ = std::vector<std::string>{"alpha", "rho", "sigma"};
    
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    
    dimss__ = std::vector<std::vector<size_t>>{std::vector<size_t>{},
      std::vector<size_t>{}, std::vector<size_t>{}};
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "alpha");
    param_names__.emplace_back(std::string() + "rho");
    param_names__.emplace_back(std::string() + "sigma");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "alpha");
    param_names__.emplace_back(std::string() + "rho");
    param_names__.emplace_back(std::string() + "sigma");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"alpha\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"rho\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"sigma\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"}]");
    
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"alpha\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"rho\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"sigma\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"}]");
    
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 
  ((1 + 1) + 1);
      const size_t num_transformed = 0;
      const size_t num_gen_quantities = 0;
      std::vector<double> vars_vec(num_params__
       + (emit_transformed_parameters * num_transformed)
       + (emit_generated_quantities * num_gen_quantities));
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        vars_vec.data(), vars_vec.size());
    }

    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 
  ((1 + 1) + 1);
      const size_t num_transformed = 0;
      const size_t num_gen_quantities = 0;
      vars.resize(num_params__
        + (emit_transformed_parameters * num_transformed)
        + (emit_generated_quantities * num_gen_quantities));
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }

    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }


    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits(context, params_i, params_r_vec, pstream);
      params_r = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        params_r_vec.data(), params_r_vec.size());
    }

  inline void transform_inits(const stan::io::var_context& context,
                              std::vector<int>& params_i,
                              std::vector<double>& vars,
                              std::ostream* pstream__ = nullptr) const {
     constexpr std::array<const char*, 3> names__{"alpha", "rho", "sigma"};
      const std::array<Eigen::Index, 3> constrain_param_sizes__{1, 1, 1};
      const auto num_constrained_params__ = std::accumulate(
        constrain_param_sizes__.begin(), constrain_param_sizes__.end(), 0);
    
     std::vector<double> params_r_flat__(num_constrained_params__);
     Eigen::Index size_iter__ = 0;
     Eigen::Index flat_iter__ = 0;
     for (auto&& param_name__ : names__) {
       const auto param_vec__ = context.vals_r(param_name__);
       for (Eigen::Index i = 0; i < constrain_param_sizes__[size_iter__]; ++i) {
         params_r_flat__[flat_iter__] = param_vec__[i];
         ++flat_iter__;
       }
       ++size_iter__;
     }
     vars.resize(num_params_r__);
     transform_inits_impl(params_r_flat__, params_i, vars, pstream__);
    } // transform_inits() 
    
};
}
using stan_model = model_gp_opt_model_namespace::model_gp_opt_model;

#ifndef USING_R

// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

stan::math::profile_map& get_stan_profile_data() {
  return model_gp_opt_model_namespace::profiles__;
}

#endif


