import Vikonanie from '../../components/Vikonanie/Vikonanie'
import { default as st11, default as st21 } from './assets/st11.png'
import { default as st12, default as st22 } from './assets/st12.png'
import st13 from './assets/st13.png'
import st14 from './assets/st14.png'

export default function VikonanieLab() {
	return (
		<Vikonanie
			vikonanieText={
				<div>
					<div>
						<p className='text-sky-500'>Виконання програми Завдання 1:</p>
						<img className='py-4' src={st11} alt='st11' />
						<img className='py-4' src={st12} alt='st12' />
						<img className='py-4' src={st13} alt='st13' />
						<img className='py-4' src={st14} alt='st14' />
					</div>
					<div>
						<p className='text-sky-500'>Виконання програми Завдання 2:</p>
						<img className='py-4' src={st21} alt='st21' />
						<img className='py-4' src={st22} alt='st22' />
					</div>
				</div>
			}
		/>
	)
}
