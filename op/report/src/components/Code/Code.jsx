import PropTypes from 'prop-types'
import GoToLabButton from '../GoToLabButton/GoToLabButton'
import Header from '../Header/Header'

Code.propTypes = {
	codeText: PropTypes.element.isRequired,
}
export default function Code({ codeText }) {
	return (
		<div className='bg-gray-50 h-vh py-24 sm:py-32'>
			<Header />
			<div className='mx-auto max-w-7xl px-6 lg:px-8'>
				<GoToLabButton />
				<div className='mx-auto max-w-4xl lg:mx-0'>
					<h2 className='text-4xl font-bold tracking-tight text-gray-900 sm:text-6xl'>
						Код програми
					</h2>
					<p className='mt-6 text-gray-600'>{codeText}</p>
				</div>
			</div>
		</div>
	)
}
