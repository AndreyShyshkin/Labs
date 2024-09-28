import Vikonanie from '../../components/Vikonanie/Vikonanie'

export default function VikonanieLab() {
	return (
		<Vikonanie
			vikonanieText={
				<div>
					<div>
						<p className='text-sky-500'>Виконання програми Завдання 1:</p>
						<img className='py-4' src='/src/assets/st11.png' alt='st11' />
						<img className='py-4' src='/src/assets/st12.png' alt='st12' />
						<img className='py-4' src='/src/assets/st13.png' alt='st13' />
						<img className='py-4' src='/src/assets/st14.png' alt='st14' />
					</div>
					<div>
						<p className='text-sky-500'>Виконання програми Завдання 2:</p>
						<img className='py-4' src='/src/assets/st21.png' alt='st21' />
						<img className='py-4' src='/src/assets/st22.png' alt='st22' />
					</div>
				</div>
			}
		/>
	)
}
