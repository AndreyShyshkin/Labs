import Katalog from '../../components/Katalog/Katalog'

export default function LabsKatalog() {
	const currentPath = window.location.pathname

	const NumLabs = str => {
		const numberMatch = str.match(/\d+/)
		return numberMatch
			? numberMatch[0]
			: 'Не знайдено номер лабораторной роботи'
	}
	return (
		<div className='pt-24 sm:pt-32'>
			<div className='mx-auto max-w-2xl px-6 lg:max-w-7xl lg:px-8'>
				<h2 className='text-center text-base/7 font-semibold text-indigo-600'>
					Каталог. Лабораторнa робота {NumLabs(currentPath)}
				</h2>
				<p className='mx-auto mt-2 max-w-lg text-pretty text-center text-4xl font-medium tracking-tight text-gray-950 sm:text-5xl'>
					Виберіть що ви хочете переглянути
				</p>
				<div className='mt-10 grid gap-4 sm:mt-16 lg:grid-cols-3 lg:grid-rows-2'>
					<Katalog
						name='Мета роботи'
						img='https://cdn-icons-png.flaticon.com/512/599/599224.png'
						linkUrl={`${currentPath}/meta-roboti`}
					/>
					<Katalog
						name='Умова роботи'
						img='https://cdn-icons-png.flaticon.com/512/1356/1356627.png'
						linkUrl={`${currentPath}/umova-roboti`}
					/>
					<Katalog
						name='Аналіз роботи'
						img='https://cdn-icons-png.flaticon.com/512/1006/1006585.png'
						linkUrl={`${currentPath}/analiz-roboti`}
					/>
					<Katalog
						name='Блок-схема'
						img='https://cdn-icons-png.flaticon.com/512/2145/2145691.png'
						linkUrl={`${currentPath}/block-scheme`}
					/>
					<Katalog
						name='Код програми'
						img='https://cdn-icons-png.flaticon.com/512/59/59118.png'
						linkUrl={`${currentPath}/code-programm`}
					/>
					<Katalog
						name='Виконання програми'
						img='https://cdn-icons-png.flaticon.com/512/1352/1352802.png'
						linkUrl={`${currentPath}/vikonanie-programm`}
					/>
					<Katalog
						name='Перевірка достовірності'
						img='https://cdn-icons-png.flaticon.com/512/5145/5145815.png'
						linkUrl={`${currentPath}/perverka-dostovirnosti`}
					/>
					<Katalog
						name='Висновок'
						img='https://cdn-icons-png.flaticon.com/512/8916/8916300.png'
						linkUrl={`${currentPath}/vysnovok`}
					/>
				</div>
			</div>
		</div>
	)
}
