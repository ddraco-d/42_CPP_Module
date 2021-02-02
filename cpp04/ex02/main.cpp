/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:56:36 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:31:31 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	TacticalMarine tacticalMarine;
	AssaultTerminator assaultTerminator;
	std::cout << std::endl << std::endl;
	
	ISpaceMarine* cloneAssault = assaultTerminator.clone();
	cloneAssault->rangedAttack();
	std::cout << std::endl << std::endl;

	std::cout << "__COPY AND ASSIGN TEST__\n\n";
	Squad squad;
	squad.push(tacticalMarine.clone());
	squad.push(assaultTerminator.clone());
	Squad squadCheckAssign;
	squadCheckAssign = squad;
	Squad squadCheckCopyConstructor(squadCheckAssign);

	std::cout << squad.getCount() << std::endl;
	squad.getUnit(0)->battleCry();
	squad.getUnit(1)->battleCry();
	delete cloneAssault;
	
	
	std::cout << "\n___Subject-check main___\n\n";

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	
	std::cout << "\n\n__END Subject-Check main___\n\n";
	return 0;
}
