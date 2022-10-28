#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_SLOTS 4

class MateriaSource : public IMateriaSource {

	private:
		AMateria *m_materias[MAX_SLOTS];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copyMateriaSrc);
		MateriaSource &operator=(const MateriaSource &materia);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);

		void getMateriaSources(void);
};

#endif