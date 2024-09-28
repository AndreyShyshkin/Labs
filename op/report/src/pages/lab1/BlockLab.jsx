import Block from '../../components/Block/Block'

export default function BlockLab() {
	return (
		<Block
			blockText={
				<div className='flex justify-between'>
					<div>
						<p className='text-sky-500'>Блок схема Завдання 1:</p>
						<img
							className='py-4'
							src='/src/pages/lab1/assets/block1.jpg'
							alt='block1'
						/>
					</div>
					<div>
						<p className='text-sky-500'>Блок схема Завдання 2:</p>
						<img
							className='py-4'
							src='/src/pages/lab1/assets/block2.jpg'
							alt='block2'
						/>
					</div>
				</div>
			}
		/>
	)
}
