/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 22:54:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>

/*
	The functions with const are functions that CANNOT change values of
	the object.
*/
class Fixed
{
	private:
		int 				number_value;
		static const int	number_fractional_bits;

	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		void 		operator=(Fixed &copy);
		int			getRawBits(void);
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		std::string	operator<<(const Fixed &copy); 
};

#endif
