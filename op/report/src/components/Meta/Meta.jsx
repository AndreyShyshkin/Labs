import PropTypes from 'prop-types'
import GoToLabButton from '../GoToLabButton/GoToLabButton'

Meta.propTypes = {
	metaText: PropTypes.element.isRequired,
}
export default function Meta({ metaText }) {
	return (
		<div className='py-24 sm:py-32'>
			<div className='mx-auto max-w-7xl px-6 lg:px-8'>
				<GoToLabButton />
				<div className='mx-auto max-w-2xl lg:mx-0'>
					<h2 className='text-4xl font-bold tracking-tight text-gray-900 sm:text-6xl'>
						Мета роботи
					</h2>
					<p className='mt-6 text-lg leading-8 text-gray-600'>{metaText}</p>
				</div>
			</div>
		</div>
	)
}
