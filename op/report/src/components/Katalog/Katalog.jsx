import PropTypes from 'prop-types'
import { Link } from 'react-router-dom'

Katalog.propTypes = {
	name: PropTypes.string.isRequired,
	img: PropTypes.string.isRequired,
	linkUrl: PropTypes.string.isRequired,
}
export default function Katalog({ name, img, linkUrl }) {
	return (
		<Link to={linkUrl}>
			<div className='relative max-lg:row-start-1'>
				<div className='absolute inset-px rounded-lg bg-white max-lg:rounded-t-[2rem]'></div>
				<div className='relative flex h-full flex-col overflow-hidden rounded-[calc(theme(borderRadius.lg)+1px)] max-lg:rounded-t-[calc(2rem+1px)]'>
					<div className='px-8 pt-4 sm:px-10 sm:pt-5'>
						<p className='text-lg/7 font-medium tracking-tight text-gray-950 max-lg:text-center'>
							{name}
						</p>
					</div>
					<div className='flex flex-1 items-center justify-center px-8 py-6 max-lg:pt-10 sm:px-10'>
						<img className='max-lg:max-w-xs h-24 w-24' src={img} alt={name} />
					</div>
				</div>
				<div className='pointer-events-none absolute inset-px rounded-lg shadow ring-1 ring-black/5 max-lg:rounded-t-[2rem]'></div>
			</div>
		</Link>
	)
}
