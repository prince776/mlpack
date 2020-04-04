/**
 * @file layer_name_visitor_impl.hpp
 * @author Marcus Edel
 *
 * Implementation of the Name() function layer abstraction.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_METHODS_ANN_VISITOR_OUTPUT_PARAMETER_VISITOR_IMPL_HPP
#define MLPACK_METHODS_ANN_VISITOR_OUTPUT_PARAMETER_VISITOR_IMPL_HPP

// In case it hasn't been included yet.
#include "layer_name_visitor.hpp"

namespace mlpack {
namespace ann {

//! LayerNameVisitor visitor class.
template<typename LayerType>
inline std::string& LayerNameVisitor::operator()(LayerType *layer) const
{
  return layer->Name();
}

inline std::string& LayerNameVisitor::operator()(MoreTypes layer) const
{
  return layer.apply_visitor(*this);
}

} // namespace ann
} // namespace mlpack

#endif
