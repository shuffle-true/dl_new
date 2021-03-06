#pragma once

# include <Eigen/Core>
# include "../Config.h"


namespace activate{
    /*!
    * \details Класс функции активации - Identity.
    */
    class Identity
    {
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;

    public:
        /// __Алгоритм__:
        /// \code
        /// int identity_forward(const Matrix& Z, Matrix& A){
        ///
        ///     A = Z;
        ///
        /// }
        /// \endcode
        /// \param Z значения нейронов до активации
        /// \param A значения нейронов после активации
        static inline void activate(const Matrix& Z, Matrix& A)
        {
            A.array() = Z.array();
        }

        /// Операция матричного дифференцирования.

        /// __Алгоритм__:
        /// \code
        /// int identity_backprop(const Matrix& Z, const Matrix& A,
        ///		const Matrix& F, Matrix& G) {
        ///
        ///     G = F;
        ///
        /// }
        /// \endcode
        /// \param Z нейроны слоя до активации.
        /// \param A нейроны слоя после активации.
        /// \param F нейроны следующего слоя.
        /// \param G значения, которые получаются после backprop.
        static inline void apply_jacobian(const Matrix& Z, const Matrix& A,
                                          const Matrix& F, Matrix& G)
        {
            G.array() = F.array();
        }

        ///
        /// \return Тип активации.
        static std::string return_type()
        {
            return "Identity";
        }
    };
}

