/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/29 23:29:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>

/*
	The prefix increment /decrement  HAS NOT params.
		and it returns the reference to object
	The suffix increment /decrement MUST HAVE params.
		and it does NOT return the reference to object.

		The postfix args MUST have an int arg.
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
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		
		Fixed&		operator++(void);
		Fixed		operator++(int arg);
		Fixed&		operator--(void);
		Fixed		operator--(int arg);

		static Fixed&	min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed&	min(Fixed &fixed1, Fixed &fixed2);
		static Fixed&	max(Fixed &fixed1, Fixed &fixed2);
		static Fixed&	max(Fixed const &fixed1, Fixed const &fixed2);

};

bool		operator<(Fixed const &num1, Fixed const &num2);
bool		operator>(Fixed const &num1, Fixed const &num2);
bool		operator<=(Fixed const &num1, Fixed const &num2);
bool		operator>=(Fixed const &num1, Fixed const &num2);
bool		operator==(Fixed const &num1, Fixed const &num2);
bool		operator!=(Fixed const &num1, Fixed const &num2);
Fixed		operator+(Fixed const &num1, Fixed const &num2);
Fixed		operator-(Fixed const &num1, Fixed const &num2);
Fixed		operator*(Fixed const &num1, Fixed const &num2);
Fixed		operator/(Fixed const &num1, Fixed const &num2);

/*We MUST define this operator here because the seconds param always is this and 
in this case we need the second arg like copy of Fixed*/
std::ostream&	operator<<(std::ostream &, const Fixed &copy); 

#endif
