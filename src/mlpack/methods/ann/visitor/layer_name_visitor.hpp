/**
 * @file layer_name_visitor.hpp
 * @author Prince Gupta
 *
 * This file provides an abstraction for the Name() function for
 * different layers and automatically provides the corresponding name.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_METHODS_ANN_VISITOR_LAYER_NAME_VISITOR_HPP
#define MLPACK_METHODS_ANN_VISITOR_LAYER_NAME_VISITOR_HPP

#include <mlpack/methods/ann/layer/layer_traits.hpp>
#include <mlpack/methods/ann/layer/layer_types.hpp>

#include <boost/variant.hpp>

namespace mlpack {
namespace ann {

/**
 * LayerNameVisitor exposes the name of the given module.
 */
class LayerNameVisitor : public boost::static_visitor<arma::mat&>
{
 public:
  //! Return the output parameter set.
  template<typename LayerType>
  std::string& operator()(LayerType* layer) const;

  std::stringarma::mat& operator()(MoreTypes layer) const;
};

} // namespace ann
} // namespace mlpack

// Include implementation.
#include "layer_name_visitor_impl.hpp"

#endif
