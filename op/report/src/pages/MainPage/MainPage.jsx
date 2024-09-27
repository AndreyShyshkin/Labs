import { Link } from 'react-router-dom'
import BackGroundDown from '../../components/BackGround/BackGroundDown'
import BackGroundUp from '../../components/BackGround/BackGroundUp'
import Header from '../../components/Header/Header'
import './MainPage.css'

export default function MainPage() {
	return (
		<div className='bg-white'>
			<Header />
			<div className='relative isolate px-6 pt-14 lg:px-8'>
				<BackGroundUp />
				<div className='max-w-5xl m-auto py-32 sm:py-48 lg:py-56 flex justify-between'>
					<div className='text-left m-auto'>
						<h1 className='text-4xl font-bold tracking-tight text-gray-900 sm:text-6xl'>
							Звіти по лабораторних роботах по ОП
						</h1>
						<p className='mt-6 text-lg leading-8 text-gray-600'>
							Виконав Шишкін Андрій ІПЗ-11.1
							<br />
							Викладач Ковалюк Тетяна Володимирівна
						</p>
					</div>
					<div className='labs'>
						<Link
							className='mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2'
							to='/lab1'
						>
							Лабораторна работа №1
						</Link>
						<Link
							className='mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2'
							to='/lab2'
						>
							Лабораторна работа №2
						</Link>
					</div>
				</div>
				<BackGroundDown />
			</div>
		</div>
	)
}
