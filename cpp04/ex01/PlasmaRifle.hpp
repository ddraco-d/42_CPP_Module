/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:01:47 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:37:20 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon 
{
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &other);
	PlasmaRifle& operator=(const PlasmaRifle& plasmaRifle);
	virtual ~PlasmaRifle();
	void attack() const;
};

#endif
