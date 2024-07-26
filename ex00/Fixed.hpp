/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 22:40:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

	private:
		int 				number_value;
		static const int	number_fractional_bits;

	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		~Fixed(void);
		void 	operator=(Fixed &copy);
		int		getRawBits(void);
		void	setRawBits(int const raw);

};

#endif
