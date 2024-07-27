/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/27 19:57:49 by gabriel          ###   ########.fr       */
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
		Fixed		&operator=(Fixed const &copy);
		int			getRawBits(void);
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

/*We MUST define this operator here because the seconds param always is this and 
in this case we need the second arg like copy of Fixed*/
std::ostream&	operator<<(std::ostream &, const Fixed &copy); 

#endif
