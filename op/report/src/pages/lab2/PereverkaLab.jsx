import Pereverka from '../../components/Pereverka/Pereverka'
import p1 from './assets/p1.png'
import p2 from './assets/p2.png'
import pc1 from './assets/pc1.jpg'
import pc21 from './assets/pc21.jpg'
import pc22 from './assets/pc22.jpg'
import pc23 from './assets/pc23.jpg'
import pc24 from './assets/pc24.jpg'

export default function PereverkaLab() {
	return (
		<Pereverka
			pereverkaText={
				<div>
					<div>
						<p className='text-sky-500'>Виконання програми Завдання 1:</p>
						<img className='py-4' src={p1} alt='p1' />
						<img className='py-4 w-72' src={pc1} alt='pc1' />
					</div>
					<div>
						<p className='text-sky-500'>Виконання програми Завдання 2:</p>
						<img className='py-4' src={p2} alt='p2' />
						<p>Розраховуємо сторому ромбу:</p>
						<img className='py-4 w-72' src={pc21} alt='pc21' />
						<p>
							Обчислюємо половину сторони (оскільки висота ділить сторону
							навпіл)
						</p>
						<img className='py-4 w-72' src={pc22} alt='pc22' />
						<p>Обчислюємо висоту ромба за теоремою Піфагора</p>
						<img className='py-4 w-72' src={pc23} alt='pc23' />
						<p>Обчислюємо меншу діагональ (це подвоєна висота)</p>
						<img className='py-4 w-72' src={pc24} alt='pc24' />
					</div>
				</div>
			}
		/>
	)
}
