import PropTypes from 'prop-types'
import GoToLabButton from '../GoToLabButton/GoToLabButton'

Vysnovok.propTypes = {
	vysnovokText: PropTypes.element.isRequired,
}
export default function Vysnovok({ vysnovokText }) {
	return (
		<div className='py-24 sm:py-32'>
			<div className='mx-auto max-w-7xl px-6 lg:px-8'>
				<GoToLabButton />
				<div className='mx-auto max-w-4xl lg:mx-0'>
					<h2 className='text-4xl font-bold tracking-tight text-gray-900 sm:text-6xl'>
						Висновок
					</h2>
					<p className='mt-6 text-gray-600'>{vysnovokText}</p>
				</div>
			</div>
		</div>
	)
}
