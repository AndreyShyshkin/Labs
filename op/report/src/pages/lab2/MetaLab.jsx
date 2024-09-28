import Meta from '../../components/Meta/Meta'

export default function MetaLab() {
	return (
		<Meta
			metaText={
				<ol className='list-decimal'>
					<li>
						Вивчити особливості використання вбудованих типів даних:{' '}
						<span className='text-sky-500'>
							char, int, long, short, float, double, unsigned char, unsigned
							int, unsigned long
						</span>
						.
					</li>
					<li>
						Вивчити особливості використання функцій введення - виведення.
					</li>
					<li>Навчитися застосовувати стандартні математичні функції.</li>
				</ol>
			}
		/>
	)
}
