#include <linreg_predictor.h>

#include <numeric>
#include <cassert>
#include <stdexcept>


LinregPredictor::LinregPredictor(const std::vector<double>& coef)
    : coef_{coef}
{
}

double LinregPredictor::predict(const features& feat) const {
    if (feat.size() + 1 != coef_.size()) {
        throw std::runtime_error{"Vectors size mismatch"};
    }
    return  std::inner_product(feat.cbegin(), feat.cend(), ++coef_.cbegin(), coef_.front());
}
