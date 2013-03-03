#ifndef Magnum_Shaders_VectorShader_h
#define Magnum_Shaders_VectorShader_h
/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

/** @file
 * @brief Class Magnum::Shaders::VectorShader, typedef Magnum::Shaders::VectorShader2D, Magnum::Shaders::VectorShader3D
 */

#include "Math/Matrix3.h"
#include "Math/Matrix4.h"
#include "AbstractVectorShader.h"

#include "magnumShadersVisibility.h"

namespace Magnum { namespace Shaders {

/**
@brief Vector shader

Renders vector art in plain grayscale form. See also DistanceFieldVectorShader
for more advanced effects.
@see VectorShader2D, VectorShader3D
*/
template<UnsignedInt dimensions> class MAGNUM_SHADERS_EXPORT VectorShader: public AbstractVectorShader<dimensions> {
    public:
        VectorShader();

        /**
         * @brief Set transformation and projection matrix
         * @return Pointer to self (for method chaining)
         */
        inline VectorShader* setTransformationProjectionMatrix(const typename DimensionTraits<dimensions>::MatrixType& matrix) {
            AbstractShaderProgram::setUniform(transformationProjectionMatrixUniform, matrix);
            return this;
        }

        /**
         * @brief Set fill color
         * @return Pointer to self (for method chaining)
         */
        inline VectorShader* setColor(const Color4<>& color) {
            AbstractShaderProgram::setUniform(colorUniform, color);
            return this;
        }

    private:
        Int transformationProjectionMatrixUniform,
            colorUniform;
};

/** @brief Two-dimensional vector shader */
typedef VectorShader<2> VectorShader2D;

/** @brief Three-dimensional vector shader */
typedef VectorShader<3> VectorShader3D;

}}

#endif
