import Block from '../../components/Block/Block'
import block1 from './assets/block1.jpg'
import block2 from './assets/block2.jpg'

export default function BlockLab() {
	return (
		<Block
			blockText={
				<div className='flex justify-between'>
					<div>
						<p className='text-sky-500'>Блок схема Завдання 1:</p>
						<img className='py-4' src={block1} alt='block1' />
					</div>
					<div>
						<p className='text-sky-500'>Блок схема Завдання 2:</p>
						<img className='py-4' src={block2} alt='block2' />
					</div>
				</div>
			}
		/>
	)
}
